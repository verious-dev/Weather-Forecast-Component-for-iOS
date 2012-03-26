//
//  LicenseMgr.h
//

/**
 * @mainpage Verious License Manager
 *
 * @section intro Introduction
 * This library is intented to be used by both application
 * developers and component developers.  For application
 * developers, the LicenseMgr and LMCompletionDelegate APIs
 * will be used.  For component developers, the
 * LMComponentDelegate would need to be implemented.
 *
 * @section type For Application Developers
 * Before an application developer can use components purchased
 * from Verious, they must first register their license key
 * with the component they wish to associate.  This is done
 * through LicenseMgr's "registerLicense" call.  This will be
 * done once for each purchased component.  Once all components
 * have been registered, a call to LicenseMgr's "validateLicense"
 * should be made.  This makes a single request to Verious'
 * license validation server.  On return, the registered
 * components will be notified whether their associated licenses
 * are valid or not, after which they should act accordingly.
 * Application developers are notified when the license validation
 * check is complete by calling the LMCompletionDelegate delegate.
 *
 * @section type For Component Developers
 * Component developers need only to implement the
 * LMComponentDelegate's "initWithLicense" call.  When the application
 * developer calls LicenseMgr's "validateLicense", the license
 * manager will wait for a response from the Verious license
 * validation server.  When a response comes, the LicenseMgr
 * will process the response.  Then, it will call the
 * LMComponentDelegate "initialize" delegate with two parameters.
 * The first is a signed message digest.  The second is the
 * license validation message.  Component developers should check
 * the digest signature and then use the digest to authenticate
 * the license validation message.  Once authenticated, the message
 * can be parsed to determine the license details (e.g. validity,
 * expiration, etc.)
 */

#import <Foundation/Foundation.h>

/**
 * Component developers must implement this delegate in order for
 * application developers to associate their purchased license key
 * with the component.  When license validation receives a response
 * from the validation server, it will call "initWithLicense" so that
 * the component can be initialized.  Also, it will be passed a
 * signed message digest along with the message indicating license
 * validity.
 */
@protocol LMComponentDelegate

/**
 * When license validation receives a response from the validation
 * server, it will call "initWithLicense" so that the component can
 * be initialized.  Also, it will be passed a signed message digest
 * along with the message indicating license validity.  Component
 * developers should check the signed hash and hash value against
 * the message to ensure authenticity.  After this check, the
 * component can check to see if the license itself is valid or not
 * before continuing.
 *
 * @param signedHash The signed message digest
 * @param validity The message that will indicate license validity
 */
- (void)initWithLicense:(NSData*)signedHash validity:(NSString*)validity;

@end

/**
 * Application developers that embed purchased components should
 * implement this delegate so that they know when the license
 * validation is complete.  The license validation through the
 * LicenseMgr's "validateLicense" call is asynchronous as it
 * connects to the Verious license validation server.  When the
 * processing is complete and the response returns, this delegate
 * will be called to notify the application developer that a
 * response has been received and processed by the registered
 * components.
 */
@protocol LMCompletionDelegate

/**
 * Called when the license validity check returns.  The components
 * will have been initialized with the license information.  At this
 * point, the application developer can call the components' APIs.
 */
- (void)licenseCheckCompleted;

@end

/**
 * A single shared instance of this class exists to keep track of the licenses
 * an application has and associates them with their respective components.
 * Typically, an application developer will make calls to "registerLicense"
 * to register a license string purchased from Verious with a component that
 * will receive the license response.  After the registration call(s) are
 * complete, a single call to "validateLicense" is made to send the request to
 * the Verious validation servers for validation.
 */
@interface LicenseMgr : NSObject {
}

/**
 * Gets a single shared instance of the license manager.
 *
 * @return A single shared instance of the license manager
 */
+ (LicenseMgr*)instance;

/**
 * Invoked by the application using the component to register a license key
 * with a component.  Application developers should call this function once
 * for each component with the respective license key for that component.
 *
 * @param license The license key obtained from Verious
 * @param componentDelegate The component to receive the license
 */
- (void)registerLicense:(NSString*)license component:(id<LMComponentDelegate>)componentDelegate;

/**
 * After an application developer calls registerLicense for the components
 * that were purchased, validateLicenses should be called to validate the
 * license keys against the Verious server.  When the validation is
 * complete, the delegate will be called to notify the application
 * developer that they can use the component.
 *
 * @param completeDelegate Receives a message when the validation is complete
 */
- (void)validateLicenses:(id<LMCompletionDelegate>)completeDelegate;

@end
