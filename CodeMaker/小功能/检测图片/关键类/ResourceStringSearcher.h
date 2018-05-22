
#import <Foundation/Foundation.h>

extern NSString * const kNotificationResourceStringQueryDone;

#pragma mark - ResourceStringPattern

@interface ResourceStringPattern : NSObject

@property (strong, nonatomic) NSString *suffix;
@property (assign, nonatomic) BOOL enable;
@property (strong, nonatomic) NSString *regex;
@property (assign, nonatomic) NSInteger groupIndex;

- (id)initWithDictionary:(NSDictionary *)dict;

@end


#pragma mark - ResourceStringSearcher

@interface ResourceStringSearcher : NSObject

@property (strong, nonatomic, readonly) NSMutableSet *resStringSet;

+ (instancetype)sharedObject;

- (void)startWithProjectPath:(NSString *)projectPath excludeFolders:(NSArray *)excludeFolders resourceSuffixs:(NSArray *)resourceSuffixs resourcePatterns:(NSArray *)resourcePatterns;

- (void)reset;

- (BOOL)containsResourceName:(NSString *)name;

/**
 *  If resource name is: "icon_tag_1.png", and using in code by "icon_tag_%d", this resource is used with a similar name.
 *
 *  @param name resource name
 *
 *  @return BOOL
 */
- (BOOL)containsSimilarResourceName:(NSString *)name;

- (NSArray *)createDefaultResourcePatternsWithResourceSuffixs:(NSArray *)resSuffixs;

- (NSDictionary *)createEmptyResourcePattern;

@end
