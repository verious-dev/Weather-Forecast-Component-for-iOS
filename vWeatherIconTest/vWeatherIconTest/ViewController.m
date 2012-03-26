//
//  ViewController.m
//  vWeatherIconTest
//
//  Created by Lu Gan on 3/9/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController
@synthesize veriousContainerView;
@synthesize iconViewController;

static NSString *NibFileName = @"IconViewController";

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
    
    
    
    if([[NSBundle mainBundle] pathForResource:NibFileName ofType:@"nib"] != nil) 
    {     
        iconViewController = [[IconViewController alloc] initWithNibName:NibFileName bundle:nil];
        // lm
        [[LicenseMgr instance] registerLicense:@"e3a548c96e8fa7f901b5a9acdf0aade2" component:iconViewController];
        [[LicenseMgr instance] validateLicenses:self];
    } else {
        NSLog(@"Can't find NIB file %@", NibFileName);
    }
    [veriousContainerView addSubview:iconViewController.view];


}

- (void)licenseCheckCompleted {
    NSLog(@"Done checking licenses");
}

- (void)viewDidUnload
{
    [self setVeriousContainerView:nil];
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
    [veriousContainerView release];
    [super dealloc];
}
@end
