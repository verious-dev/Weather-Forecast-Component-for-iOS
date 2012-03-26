//
//  ViewController.h
//  vWeatherIconTest
//
//  Created by Lu Gan on 3/9/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LicenseMgr.h"
#import <VeriousWeatherFramework/IconViewController.h>
#import <VeriousWeatherFramework/Weather.h>

@interface ViewController : UIViewController <LMCompletionDelegate> {
    IconViewController *iconViewController;
}
@property (retain, nonatomic) IconViewController *iconViewController;
@property (retain, nonatomic) IBOutlet UIView *veriousContainerView;

- (void)licenseCheckCompleted;

@end
