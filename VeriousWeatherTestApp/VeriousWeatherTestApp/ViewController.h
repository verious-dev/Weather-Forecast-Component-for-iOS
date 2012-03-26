//
//  ViewController.h
//  VeriousWeatherTestApp
//
//  Created by Lu Gan on 2/17/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <VeriousWeatherFramework/BarViewController.h>
#import <VeriousWeatherFramework/Weather.h>
#import "LicenseMgr.h"

@interface ViewController : UIViewController <LMCompletionDelegate> {
    BarViewController *barViewController;
}


@property (retain, nonatomic) IBOutlet UIView *testView;
@property (retain, nonatomic) NSString *status;

- (void)licenseCheckCompleted;

@end
