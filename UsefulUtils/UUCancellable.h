#import <Foundation/Foundation.h>

#import "UUMacros.h"

NS_ASSUME_NONNULL_BEGIN

///
/// An object to represent an operation which can optionally be cancelled.
/// It is not necessary to retain a reference to this object
/// if it does not need to be cancelled.
///
@interface UUCancellable : NSObject

///
/// Initialize a new cancellable with the given cancellation block.
/// @param block The cancellation block which can be used to perform whatever
///              operations are necessary to cancel the operation.
///              This block is not guaranteed to be called, but would not
///              be called more than once.
///
- (instancetype)initWithCancellationBlock:(void (^)())block $designated;

- (instancetype)init $unavailable;

///
/// End the operation associated with this cancellable.
///
- (void)cancel;

///
/// Merge a collection of cancellable objects into one such that
/// they can all be cancelled at once.
///
+ (UUCancellable *)coalesceCancellables:(NSArray<UUCancellable *> *)cancellables;

@end

NS_ASSUME_NONNULL_END
