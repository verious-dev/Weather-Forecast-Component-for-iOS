# Weather Forcast Component for IOS

This project uses Weather Forecast Component in two ways:
* Weather Bar Widget - See project VeriousWeatherTestApp
* Weather Icon - See project vWeatherIconTest

## Further Reading
* [Wiki Page](http://github.com/verious-dev/Weather-Forecast-Component-for-iOS/wiki)
* [Component Detail](http://www.verious.com/component/weather-forecast/)

## Install Instructions
* Download the repository
* Expand the folder to find following projects:
   * VeriousWeatherTestApp
   * vWeatherIconTest
* Run individual projects to see the application in work

## License
This project is currently using a 30 days trial license key.
Sign-up and get your own perpetual license from:
http://www.verious.com/component/weather-forecast/

## Documentation
Read "Integrating Verious Weather Components in Your Application for iOS.pdf" for detailed component instructions

Register your license using:
`[[LicenseMgr instance] registerLicense:@"1d42d0f0009b60d76edc01d844d5a657" component:barViewController];`
`[[LicenseMgr instance] validateLicenses:self];`


To use Weather Bar widget:
`barViewController = [[BarViewController alloc] initWithNibName:fileName bundle:nil];`
`[testView addSubview:barViewController.view];`

