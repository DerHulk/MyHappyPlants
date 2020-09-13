import { CommandModelAbstract } from "./commandModelAbstract";

export class GetClimateCommandModel extends CommandModelAbstract {

  constructor() {
    super('Get Climate Data', '2');
  }

  public ParseResponse(response: string): string[] {
    const fragements = response.split(';');

    if (fragements.length !== 2) {
      return ['Unkown Response'];
    }

    fragements[0] = 'Temperature: ' + fragements[0] + '°';
    fragements[1] = 'Humidity: ' + fragements[1] + '%';
    fragements[2] = 'Head-Index: ' + fragements[2] + '°';

    return fragements;
  }

}
