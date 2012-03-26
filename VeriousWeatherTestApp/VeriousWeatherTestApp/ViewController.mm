//
//  ViewController.m
//  VeriousWeatherTestApp
//
//  Created by Lu Gan on 2/17/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ViewController.h"


@implementation ViewController
@synthesize testView;
@synthesize status;

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    

	// Do any additional setup after loading the view, typically from a nib.
    [[UIApplication sharedApplication] setStatusBarOrientation:UIInterfaceOrientationPortrait];

    
    NSString *fileName = @"BarViewController_iPhone";
    
    NSArray *allFrameworkBundles = [NSBundle allFrameworks];
    for (NSBundle *bundle in allFrameworkBundles) {
        NSLog(@"...... bundle identifier: %@", [bundle bundleIdentifier]);
    }
//    NSBundle *weatherFrameworkBundle = [NSBundle bundleWithIdentifier:@"VeriousWeatherFramework"];
//    NSBundle *aBundle = [NSBundle bundleForClass:[BarViewController class]];
//    NSLog(@"bundle identifier %@", [aBundle bundleIdentifier]);
//    
//	NSString *path = [[NSBundle mainBundle] resourcePath];
//	path = [NSString stringWithFormat:@"%@/%@", path, fileName];
    
//    if([aBundle pathForResource:fileName ofType:@"nib"] != nil) 
//    {     
//        barViewController = [[BarViewController alloc] initWithNibName:fileName bundle:aBundle];
//    } else {
//        NSLog(@"Can't find NIB file %@", fileName);
//    }
    
    if([[NSBundle mainBundle] pathForResource:fileName ofType:@"nib"] != nil) 
    {     
        barViewController = [[BarViewController alloc] initWithNibName:fileName bundle:nil];
        // lm
        [[LicenseMgr instance] registerLicense:@"9eb308951de2f41f8c66f0fee17da929" component:barViewController];
        [[LicenseMgr instance] validateLicenses:self];
    } else {
        NSLog(@"Can't find NIB file %@", fileName);
    }
//    testView = barViewController.view;
    
    [testView addSubview:barViewController.view];
}


- (void)licenseCheckCompleted {
    NSLog(@"Done checking licenses");
}


- (void)viewDidUnload
{
    [self setTestView:nil];
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
	[super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

- (void)dealloc {
    [testView release];
    [super dealloc];
}
@end
