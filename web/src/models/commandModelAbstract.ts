export abstract class CommandModelAbstract {

  constructor(
    public titel: string,
    public bluetoothCommand: string) {
  }

  public abstract ParseResponse(response: string): string[];

}
