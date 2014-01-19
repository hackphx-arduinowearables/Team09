//
//  ScoreBoardView.m
//  OpenBLE
//
//  Created by Jeffrey Kunzelman on 1/18/14.
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import "ScoreBoardView.h"

@implementation ScoreBoardView

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
    }
    return self;
}

// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    //// General Declarations
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    //// Color Declarations
    UIColor* color = [UIColor colorWithRed: 1 green: 0.343 blue: 0.343 alpha: 1];
    UIColor* color2 = [UIColor colorWithRed: 0.886 green: 0 blue: 0 alpha: 1];
    UIColor* color3 = [UIColor colorWithRed: 0.114 green: 0.705 blue: 1 alpha: 1];
    UIColor* color4 = [UIColor colorWithRed: 0 green: 0.657 blue: 0 alpha: 1];
    UIColor* color5 = [UIColor colorWithRed: 1 green: 1 blue: 0.114 alpha: 1];
    UIColor* color6 = [UIColor colorWithRed: 1 green: 0.41 blue: 0.114 alpha: 1];
    UIColor* gradientColor = [UIColor colorWithRed: 0.323 green: 0.3 blue: 0.3 alpha: 1];
    UIColor* color7 = [UIColor colorWithRed: 0 green: 0.143 blue: 0.429 alpha: 1];
    UIColor* color8 = [UIColor colorWithRed: 0.933 green: 1 blue: 0.8 alpha: 1];
    
    //// Gradient Declarations
    NSArray* gradientColors = [NSArray arrayWithObjects:
                               (id)color.CGColor,
                               (id)gradientColor.CGColor, nil];
    CGFloat gradientLocations[] = {0, 1};
    CGGradientRef gradient = CGGradientCreateWithColors(colorSpace, (__bridge CFArrayRef)gradientColors, gradientLocations);
    
    //// Abstracted Attributes
    NSString* textContent = @"DogeFit";
    NSString* text2Content = @"Hello, World!";
    NSString* text3Content = @"Chihuahua";
    NSString* text4Content = @"Labrador ";
    NSString* text5Content = @"Golden Retriever";
    NSString* text6Content = @"Great Dane";
    NSString* text7Content = @"Cat";
    
    
    //// Rectangle Drawing
    UIBezierPath* rectanglePath = [UIBezierPath bezierPathWithRect: CGRectMake(-0.5, -1.5, 240, 402)];
    CGContextSaveGState(context);
    [rectanglePath addClip];
    CGContextDrawLinearGradient(context, gradient, CGPointMake(119.5, -1.5), CGPointMake(119.5, 400.5), 0);
    CGContextRestoreGState(context);
    [[UIColor blackColor] setStroke];
    rectanglePath.lineWidth = 1;
    [rectanglePath stroke];
    
    
    //// Rectangle 7 Drawing
    UIBezierPath* rectangle7Path = [UIBezierPath bezierPathWithRect: CGRectMake(-0.5, 265.5, 240, 66)];
    [color3 setFill];
    [rectangle7Path fill];
    [[UIColor blackColor] setStroke];
    rectangle7Path.lineWidth = 1;
    [rectangle7Path stroke];
    
    
    //// Rectangle 3 Drawing
    UIBezierPath* rectangle3Path = [UIBezierPath bezierPathWithRect: CGRectMake(-0.5, 325.5, 240, 41)];
    [color7 setFill];
    [rectangle3Path fill];
    [[UIColor blackColor] setStroke];
    rectangle3Path.lineWidth = 1;
    [rectangle3Path stroke];
    
    
    //// Rectangle 4 Drawing
    UIBezierPath* rectangle4Path = [UIBezierPath bezierPathWithRect: CGRectMake(-0.5, 201.5, 240, 66)];
    [color4 setFill];
    [rectangle4Path fill];
    [[UIColor blackColor] setStroke];
    rectangle4Path.lineWidth = 1;
    [rectangle4Path stroke];
    
    
    //// Rectangle 5 Drawing
    UIBezierPath* rectangle5Path = [UIBezierPath bezierPathWithRect: CGRectMake(-0.5, 135.5, 240, 66)];
    [color5 setFill];
    [rectangle5Path fill];
    [[UIColor blackColor] setStroke];
    rectangle5Path.lineWidth = 1;
    [rectangle5Path stroke];
    
    
    //// Rectangle 6 Drawing
    UIBezierPath* rectangle6Path = [UIBezierPath bezierPathWithRect: CGRectMake(-0.5, 69.5, 240, 66)];
    [color6 setFill];
    [rectangle6Path fill];
    [[UIColor blackColor] setStroke];
    rectangle6Path.lineWidth = 1;
    [rectangle6Path stroke];
    
    
    //// Text Drawing
    CGRect textRect = CGRectMake(27, -2, 185, 72);
    NSMutableParagraphStyle* textStyle = [[NSMutableParagraphStyle defaultParagraphStyle] mutableCopy];
    [textStyle setAlignment: NSTextAlignmentCenter];
    
    NSDictionary* textFontAttributes = @{NSFontAttributeName: [UIFont fontWithName: @"Chalkduster" size: 35], NSForegroundColorAttributeName: [UIColor blackColor], NSParagraphStyleAttributeName: textStyle};
    
    [textContent drawInRect: textRect withAttributes: textFontAttributes];
    
    
    //// Rounded Rectangle Drawing
    UIBezierPath* roundedRectanglePath = [UIBezierPath bezierPathWithRoundedRect: CGRectMake(26.5, 85.5, 65, 265) cornerRadius: 4];
    CGContextSaveGState(context);
    [roundedRectanglePath addClip];
    CGContextDrawLinearGradient(context, gradient, CGPointMake(59, 85.5), CGPointMake(59, 350.5), 0);
    CGContextRestoreGState(context);
    [[UIColor blackColor] setStroke];
    roundedRectanglePath.lineWidth = 1;
    [roundedRectanglePath stroke];
    
    
    //// Rectangle 2 Drawing
    UIBezierPath* rectangle2Path = [UIBezierPath bezierPathWithRect: CGRectMake(27.5, 119.5, 63, 230)];
    [color2 setFill];
    [rectangle2Path fill];
    [[UIColor blackColor] setStroke];
    rectangle2Path.lineWidth = 1;
    [rectangle2Path stroke];
    
    
    //// Text 2 Drawing
    CGRect text2Rect = CGRectMake(126, 97, 0, 0);
    NSMutableParagraphStyle* text2Style = [[NSMutableParagraphStyle defaultParagraphStyle] mutableCopy];
    [text2Style setAlignment: NSTextAlignmentCenter];
    
    NSDictionary* text2FontAttributes = @{NSFontAttributeName: [UIFont fontWithName: @"Helvetica" size: 12], NSForegroundColorAttributeName: [UIColor blackColor], NSParagraphStyleAttributeName: text2Style};
    
    [text2Content drawInRect: text2Rect withAttributes: text2FontAttributes];
    
    
    //// Text 3 Drawing
    CGRect text3Rect = CGRectMake(108, 95, 104, 34);
    NSMutableParagraphStyle* text3Style = [[NSMutableParagraphStyle defaultParagraphStyle] mutableCopy];
    [text3Style setAlignment: NSTextAlignmentCenter];
    
    NSDictionary* text3FontAttributes = @{NSFontAttributeName: [UIFont fontWithName: @"Chalkduster" size: [UIFont labelFontSize]], NSForegroundColorAttributeName: [UIColor blackColor], NSParagraphStyleAttributeName: text3Style};
    
    [text3Content drawInRect: text3Rect withAttributes: text3FontAttributes];
    
    
    //// Text 4 Drawing
    CGRect text4Rect = CGRectMake(94, 151, 132, 34);
    NSMutableParagraphStyle* text4Style = [[NSMutableParagraphStyle defaultParagraphStyle] mutableCopy];
    [text4Style setAlignment: NSTextAlignmentCenter];
    
    NSDictionary* text4FontAttributes = @{NSFontAttributeName: [UIFont fontWithName: @"Chalkduster" size: [UIFont labelFontSize]], NSForegroundColorAttributeName: [UIColor blackColor], NSParagraphStyleAttributeName: text4Style};
    
    [text4Content drawInRect: text4Rect withAttributes: text4FontAttributes];
    
    
    //// Text 5 Drawing
    CGRect text5Rect = CGRectMake(94, 222, 132, 34);
    NSMutableParagraphStyle* text5Style = [[NSMutableParagraphStyle defaultParagraphStyle] mutableCopy];
    [text5Style setAlignment: NSTextAlignmentCenter];
    
    NSDictionary* text5FontAttributes = @{NSFontAttributeName: [UIFont fontWithName: @"Chalkduster" size: [UIFont labelFontSize]], NSForegroundColorAttributeName: [UIColor blackColor], NSParagraphStyleAttributeName: text5Style};
    
    [text5Content drawInRect: text5Rect withAttributes: text5FontAttributes];
    
    
    //// Text 6 Drawing
    CGRect text6Rect = CGRectMake(94, 283, 132, 34);
    NSMutableParagraphStyle* text6Style = [[NSMutableParagraphStyle defaultParagraphStyle] mutableCopy];
    [text6Style setAlignment: NSTextAlignmentCenter];
    
    NSDictionary* text6FontAttributes = @{NSFontAttributeName: [UIFont fontWithName: @"Chalkduster" size: [UIFont labelFontSize]], NSForegroundColorAttributeName: [UIColor blackColor], NSParagraphStyleAttributeName: text6Style};
    
    [text6Content drawInRect: text6Rect withAttributes: text6FontAttributes];
    
    
    //// Text 7 Drawing
    CGRect text7Rect = CGRectMake(94, 332, 132, 34);
    NSMutableParagraphStyle* text7Style = [[NSMutableParagraphStyle defaultParagraphStyle] mutableCopy];
    [text7Style setAlignment: NSTextAlignmentCenter];
    
    NSDictionary* text7FontAttributes = @{NSFontAttributeName: [UIFont fontWithName: @"Chalkduster" size: [UIFont labelFontSize]], NSForegroundColorAttributeName: color8, NSParagraphStyleAttributeName: text7Style};
    
    [text7Content drawInRect: text7Rect withAttributes: text7FontAttributes];
    
    
    //// Cleanup
    CGGradientRelease(gradient);
    CGColorSpaceRelease(colorSpace);
    

}


@end
