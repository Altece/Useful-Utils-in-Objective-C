#import <UIKit/UIKit.h>

#import "UUILayoutAnchor.h"
#import "UUILayoutAttribute.h"
#import "UUILayoutScalar.h"

NS_ASSUME_NONNULL_BEGIN

@class UUILayoutAttribute;

@interface UUILayoutScaffold : NSObject

@property (nonatomic, readonly, strong) UUILayoutScalar *width;

@property (nonatomic, readonly, strong) UUILayoutScalar *height;

@property (nonatomic, readonly, strong) UUILayoutAnchor *top;

@property (nonatomic, readonly, strong) UUILayoutAnchor *bottom;

@property (nonatomic, readonly, strong) UUILayoutAnchor *leading;

@property (nonatomic, readonly, strong) UUILayoutAnchor *trailing;

@property (nonatomic, readonly, strong) UUILayoutAnchor *left;

@property (nonatomic, readonly, strong) UUILayoutAnchor *right;

@property (nonatomic, readonly, strong) UUILayoutAnchor *baseline;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithItem:(id)item;

@end

NS_ASSUME_NONNULL_END
