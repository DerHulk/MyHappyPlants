import { CommandModelAbstract } from "./commandModelAbstract";

export class GetGroundMoistureCommandModel extends CommandModelAbstract {

  constructor() {
    super('Get Ground Moisture', '1');
  }

  public ParseResponse(response: string): string[] {
    return [response];
  }

}
