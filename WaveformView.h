
// WaveformView.h

// Created by Seb Jachec on 16/11/2013.
// Copyright (c) 2013 Seb Jachec. All rights reserved.

#import <Cocoa/Cocoa.h>
#import <AVFoundation/AVFoundation.h>

/**
 * Give it a .wav and watch it plot - customise all colours, and enable trimming handles
 */
IB_DESIGNABLE
@interface WaveformView : NSView

/**
 * Returns sound duration in seconds
 */
@property (readonly) double duration;

IBInspectable @property BOOL trimEnabled;
/**
 * Returns time range using trimming handle. If trimming is disabled, trimRange is kkCMTimeZero, kCMTimePositiveInfinity
 */
@property (readonly) CMTimeRange trimRange;

@property (strong, nullable) IBInspectable NSColor *foregroundColor;
@property (strong, nullable) IBInspectable NSColor *backgroundColor;
@property (strong, nullable) IBInspectable NSColor *trimHandleColor;
@property (strong, nullable) IBInspectable NSColor *inactiveColor;

IBInspectable @property BOOL drawsCenterLine;

- (BOOL)loadFileWithPath:(nullable NSString*)filePath;
- (BOOL)loadURL:(nullable NSURL*)aURL;

- (void)play;
- (void)stop;

/**
 * Returns an NSImage with the waveform, the same size as this view's bounds
 */
- (nonnull NSImage*)waveformImage;

@end
