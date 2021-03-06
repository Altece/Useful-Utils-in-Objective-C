#import <Foundation/Foundation.h>

#import "UUMacros.h"

NS_ASSUME_NONNULL_BEGIN

@class UUSource<T>;
@class UUSubscription;
@protocol UUDispatcher;

///
/// An object which represents the occurrence of a specific event.
///
@interface UUSignal : NSObject

///
/// Initialise a new signal object.
///
- (instancetype)init $designated;

///
/// Initialize a new signal object that will notify subscribers
/// whenever a new value is pushed to the given source.
///
- (instancetype)initWithSource:(UUSource *)source $convenience;

///
/// Call on all subscribed blocks to notify them that the event has occurred.
///
- (void)notify;

///
/// Subscribe a block to be notified whenever the signal notifies its subscribers.
/// @note This is a convenience method for -subscribeNext:on:, and will use
///       the shared instance of UUDispatchImmediately.
///
- (UUSubscription *)subscribeNext:(void (^)())block;

///
/// Subscribe a block to be notified using the given dispatcher
/// whenever the signal notifies its subscribers.
///
- (UUSubscription *)subscribeNext:(void (^)())block on:(id<UUDispatcher>)dispatcher;

///
/// Merge a collection of signals into one such that when any one of them
/// have their subscribers notified, subscribers to the merged signal will
/// also be notified.
/// @note Calling -notify on the resulting signal will only notify subscribers
///       to the merged signal. Subscribers to the component signals will not
///       be notified.
///
+ (UUSignal *)coalesceSignals:(NSArray<UUSignal *> *)signals;

@end

NS_ASSUME_NONNULL_END
