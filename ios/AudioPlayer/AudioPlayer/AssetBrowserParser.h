//
//  Parser.h
//  AudioPlayer
//
//  Created by 村上 幸雄 on 13/05/08.
//  Copyright (c) 2013年 Bitz Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AssetBrowserParser;

typedef enum {
    kAssetBrowserSourceTypeNone = 0,
	kAssetBrowserSourceTypePlaylists,
	kAssetBrowserSourceTypeArtists,
	kAssetBrowserSourceTypeSongs,
	kAssetBrowserSourceTypeAlbums
} AssetBrowserSourceType;

typedef enum {
    kAssetBrowserStateNone = 0,
    kAssetBrowserStateInProgress,
    kAssetBrowserStateFinished,
    kAssetBrowserStateError,
    kAssetBrowserStateCanceled,
} AssetBrowserState;

typedef enum {
    kAssetBrowserCodeSuccess = 0,
    kAssetBrowserCodeCancel,
    kAssetBrowserCodeFailure
} AssetBrowserCode;

extern NSString *AssetBrowserErrorDomain;

@protocol AssetBrowserParserDelegate <NSObject>
- (void)parserDidFinishLoading:(AssetBrowserParser *)parser;
- (void)parser:(AssetBrowserParser *)parser didFailWithError:(NSError *)error;
- (void)parserDidCancel:(AssetBrowserParser *)parser;
@end

@interface AssetBrowserParser : NSObject

@property (assign, nonatomic) AssetBrowserSourceType        sourceType;
@property (readonly, nonatomic) AssetBrowserState           state;
@property (strong, nonatomic) NSMutableArray                *assetBrowserItems;
@property (readonly, nonatomic) NSError                     *error;
@property (weak, nonatomic) id<AssetBrowserParserDelegate>  delegate;

- (void)parse;
- (void)cancel;

@end
