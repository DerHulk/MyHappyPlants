import { Component } from '@angular/core';
import { log } from 'util';
//import 'web-bluetooth';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.sass']
})
export class AppComponent {

  public title: string;

  constructor() {

    this.title = 'MyHappyPlants :-)';
  }

  public testBluetooth() {

    const navigator = (window.navigator as Navigator);
    const log = window.console.log;

    let options = <any>{};
    options.acceptAllDevices = true;

    log('Requesting Bluetooth Device...');
    log('with ' + JSON.stringify(options));
    navigator.bluetooth.requestDevice(options)
      .then(device => {
        log('> Name:             ' + device.name);
        log('> Id:               ' + device.id);
        log('> Connected:        ' + device.gatt.connected);
      })
      .catch(error => {
        log('Argh! ' + error);
      });

  }
}
