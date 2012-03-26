//
//  ViewController.h
//  weather
//
//  Created by Lu Gan on 1/24/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "Weather.h"
#import "WeatherDelegate.h"
#import "LicenseMgr.h"
#import <Foundation/Foundation.h>

class com_verious_WeatherLicense {
private:
    static bool licenseValid;
    
public:
    static bool isValid() {
        return licenseValid;
    }
    
    static void validateLicense(NSData *signedHash, NSString *validity);
};

@class WDTDataService;

@interface BarViewController : UIViewController <WeatherDelegate, CLLocationManagerDelegate, LMComponentDelegate> {
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


- (IBAction)barButtonTouched:(id)sender;

- (void)locationManager:(CLLocationManager *)manager
    didUpdateToLocation:(CLLocation *)newLocation
           fromLocation:(CLLocation *)oldLocation;

- (void)locationManager:(CLLocationManager *)manager
       didFailWithError:(NSError *)error;

- (void)startCoreLocation;
- (void)gotWeather:(_Bool)success error:(NSError *)error;

@end
