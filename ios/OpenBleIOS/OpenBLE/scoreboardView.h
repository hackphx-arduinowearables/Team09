//
//  scoreboardView.h
//  OpenBLE
//
//  Created by Jeffrey Kunzelman on 1/18/14.
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface scoreboardView : UIView


@property (strong, nonatomic) NSNumber *score;

-(void) drawBar;

@end
