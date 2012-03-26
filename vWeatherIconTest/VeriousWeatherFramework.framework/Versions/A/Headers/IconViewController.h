//
//  IconViewController.h
//  VeriousWeatherFramework
//
//  Created by Lu Gan on 3/8/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <CoreLocation/CoreLocation.h>
#import "Weather.h"
#import "WeatherDelegate.h"
#import "LicenseMgr.h"
#import <Foundation/Foundation.h>


@class WDTDataService;


@interface IconViewController : UIViewController <WeatherDelegate, CLLocationManagerDelegate, LMComponentDelegate> {
    WDTDataService *dataService;
    CLLocationManager *locationManager;
    CLLocation *userLocation;
    NSString *WDTUrlRoot;
    //    bool licenseValid;
}

- (void)initWithLicense:(NSData *)signedHash validity:(NSString *)validity;

//@property (readonly) bool licenseValid;
@property (retain, nonatomic) WDTDataService *dataService;
@property (retain, nonatomic) IBOutlet UIImageView *wxImage;
@property (retain, nonatomic) IBOutlet UILabel *temp;
@property (retain, nonatomic) IBOutlet UILabel *location;
@property (nonatomic, retain) CLLocationManager *locationManager;  
@property (retain, nonatomic) CLLocation *userLocation;
@property (retain, nonatomic) IBOutlet UILabel *unitLabel;
@property (retain, nonatomic) NSString *WDTUrlRoot;

@property (retain, nonatomic) IBOutlet UIImageView *imageView;
@property (retain, nonatomic) IBOutlet UILabel *tempLabel;

- (IBAction)barButtonTouched:(id)sender;

- (void)locationManager:(CLLocationManager *)manager
    didUpdateToLocation:(CLLocation *)newLocation
           fromLocation:(CLLocation *)oldLocation;

- (void)locationManager:(CLLocationManager *)manager
       didFailWithError:(NSError *)error;

- (void)startCoreLocation;
- (void)gotWeather:(_Bool)success error:(NSError *)error;



@end
