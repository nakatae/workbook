//
//  ViewController.h
//  UDP
//
//  Created by 村上幸雄 on 2015/01/18.
//  Copyright (c) 2015年 村上幸雄. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITextField *inputTextField;
@property (weak, nonatomic) IBOutlet UIButton *sendButton;
@property (weak, nonatomic) IBOutlet UILabel *outputLabel;

- (IBAction)send:(id)sender;

@end

