//
//  Weather.h
//  weather
//
//  Created by Lu Gan on 1/31/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Weather : NSObject {
    NSString *_station;
    NSString *_location;
    float _stationLat;
    float _stationLong;
    NSDate *_observationTime;
    NSString *_dayOfWeekLocal;
    int _tempC;
    int _dewpointC;
    int _rhPct;
    int _apparentTempC;
    NSString *_windDirection;
    int _windSpeedKph;
    int _windGustKph;
    float _pressureMb;
    NSString *_weatherDescription;
    int _wxCode;
    NSString *_cloudCover;
    NSString *_wxIconUrl;
    NSString *_dayNight;
    int _visibilityM;
    NSString *_moonPhase;
    NSDate *_sunriseUtc;
    NSDate *_sunsetUtc;
    int _localOffsetHours;
}
@property (retain, nonatomic) NSString *location;
@property (retain, nonatomic) NSString *station;
@property (assign, nonatomic) int tempC;
@property (assign, nonatomic) int apparentTemp;
@property (assign, nonatomic) int wxCode;
@property (retain, nonatomic) NSString *wxIconUrl;
@property (assign, nonatomic) int windSpeed;
@property (retain, nonatomic) NSString *windDirection;
@property (retain, nonatomic) NSString *dayNight;
@property (retain, nonatomic) NSDate *observationTime;
@property (retain, nonatomic) NSString *dayOfWeekLocal;
@property (assign, nonatomic) int localOffsetHours;


- (Weather *) setStation:(NSString*)station andTemperature:(int)tempC andDescription:(NSString*)description 
          andHumidityPct:(int)humidityPct andWindSpeed:(int)windSpeedKph andWindDirection:(NSString*)windDirection;


@end
