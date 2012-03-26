//
//  WeatherDelegate.h
//  weather
//
//  Created by Lu Gan on 2/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol WeatherDelegate <NSObject>

- (void) gotWeather:(bool)success error:(NSError *)error;


@end
