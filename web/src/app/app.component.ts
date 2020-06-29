import { Component } from '@angular/core';
import { log } from 'util';
//import 'web-bluetooth';
//import 'chrome';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.sass']
})
export class AppComponent {

  //see https://googlechrome.github.io/samples/web-bluetooth/notifications.html
  //and https://googlechrome.github.io/samples/web-bluetooth/
  //and https://www.bluetooth.com/specifications/gatt/services/

  public title: string;
  private myCharacteristic: BluetoothRemoteGATTCharacteristic;

  constructor() {

    this.title = 'MyHappyPlants :-)';
  }

  public connect() {

    const serviceUUID = "ab0828b1-198e-4351-b779-901fa0e0371e";
    const characteristicUUID = "0972ef8c-7613-4075-ad52-756f33d4da91";
    //const characteristicUUID = "4ac8a682-9736-4e5d-932b-e9b31405049c";

    const navigator = (window.navigator as Navigator);
    const log = window.console.log;

    let options = <any>{};

    options.acceptAllDevices = true;
    options.optionalServices = [serviceUUID];

    log('Requesting Bluetooth Device...');
    log('with ' + JSON.stringify(options));
    navigator.bluetooth.requestDevice(options)
      .then(device => {
        log('> Name:             ' + device.name);
        log('> Id:               ' + device.id);
        log('> Connected:        ' + device.gatt.connected);

        return device.gatt.connect();
      })
      .then(server => {
        log('Getting Service...');
        return server.getPrimaryService(serviceUUID);
      })
      .then(service => {
        log('Getting Characteristic...');
        return service.getCharacteristic(characteristicUUID);
      })
      .then(characteristic => {
        this.myCharacteristic = characteristic;
        return this.myCharacteristic.startNotifications().then(_ => {
          log('> Notifications started');
          this.myCharacteristic.addEventListener('characteristicvaluechanged', this.handleNotifications);
        });
      })
      .catch(error => {
        log('Argh! ' + error);
      });
  }

  public disconnect() {
    if (this.myCharacteristic) {
      this.myCharacteristic.stopNotifications()
        .then(_ => {
          log('> Notifications stopped');
          this.myCharacteristic.removeEventListener('characteristicvaluechanged', this.handleNotifications);
          this.myCharacteristic.service.device.gatt.disconnect();
        })
        .catch(error => {
          log('Argh! ' + error);
        });
    }
  }

  public sendSomeData() {
    if (this.myCharacteristic) {
      log('> send some values');
      var uint8array = new TextEncoder().encode("test");
      this.myCharacteristic.writeValue(uint8array);
    }
  }

  private handleNotifications(event) {
    let value = event.target.value;
    const readed = new TextDecoder().decode(value);

    log('> Receive data...' + readed);

  }
}
