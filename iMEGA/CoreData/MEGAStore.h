#import <Foundation/Foundation.h>

#import "MEGASdkManager.h"
#import "MOOfflineNode.h"
#import "MOUser.h"
#import "MOChatDraft+CoreDataProperties.h"
#import "MOMediaDestination+CoreDataProperties.h"
#import "MOUploadTransfer+CoreDataProperties.h"
#import "MOMessage+CoreDataProperties.h"

@interface MEGAStore : NSObject

#pragma mark - Singleton Lifecycle

+ (MEGAStore *)shareInstance;

#pragma mark - Configure

- (void)configureMEGAStore;

#pragma mark - MOOfflineNode entity

- (void)insertOfflineNode:(MEGANode *)node api:(MEGASdk *)api path:(NSString *)path;
- (MOOfflineNode *)fetchOfflineNodeWithPath:(NSString *)path;
- (MOOfflineNode *)offlineNodeWithNode:(MEGANode *)node;
- (void)removeOfflineNode:(MOOfflineNode *)offlineNode;
- (void)removeAllOfflineNodes;

#pragma mark - MOUser entity

- (void)insertUserWithUserHandle:(uint64_t)userHandle firstname:(NSString *)firstname lastname:(NSString *)lastname email:(NSString *)email;
- (void)updateUserWithUserHandle:(uint64_t)userHandle firstname:(NSString *)firstname;
- (void)updateUserWithUserHandle:(uint64_t)userHandle lastname:(NSString *)lastname;
- (void)updateUserWithUserHandle:(uint64_t)userHandle email:(NSString *)email;
- (void)updateUserWithEmail:(NSString *)email firstname:(NSString *)firstname;
- (void)updateUserWithEmail:(NSString *)email lastname:(NSString *)lastname;
- (MOUser *)fetchUserWithUserHandle:(uint64_t)userHandle;
- (MOUser *)fetchUserWithEmail:(NSString *)email;

#pragma mark - MOChatDraft entity

- (void)insertOrUpdateChatDraftWithChatId:(uint64_t)chatId text:(NSString *)text;
- (MOChatDraft *)fetchChatDraftWithChatId:(uint64_t)chatId;

#pragma mark - MOMediaDestination entity

- (void)insertOrUpdateMediaDestinationWithFingerprint:(NSString *)fingerprint destination:(NSNumber *)destination timescale:(NSNumber *)timescale;
- (void)deleteMediaDestinationWithFingerprint:(NSString *)fingerprint;
- (MOMediaDestination *)fetchMediaDestinationWithFingerprint:(NSString *)fingerprint;

#pragma mark - MOUploadTransfer entity

- (void)insertUploadTransferWithLocalIdentifier:(NSString *)localIdentifier parentNodeHandle:(uint64_t)parentNodeHandle;
- (void)deleteUploadTransfer:(MOUploadTransfer *)uploadTransfer;
- (NSArray<MOUploadTransfer *> *)fetchUploadTransfers;
- (MOUploadTransfer *)fetchTransferUpdateWithLocalIdentifier:(NSString *)localIdentifier;
- (void)removeAllUploadTransfers;

#pragma mark - MOMessage entity

- (void)insertMessage:(uint64_t)messageId chatId:(uint64_t)chatId;
- (void)deleteMessage:(MOMessage *)message;
- (MOMessage *)fetchMessageWithChatId:(uint64_t)chatId messageId:(uint64_t)messageId;

@end
