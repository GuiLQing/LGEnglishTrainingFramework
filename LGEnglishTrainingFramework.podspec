#
# Be sure to run `pod lib lint LGEnglishTrainingFramework.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
    s.name             = 'LGEnglishTrainingFramework'
    s.version          = '1.1.7'
    s.summary          = 'A short description of LGEnglishTrainingFramework.'
    
    # This description is used to generate tags and improve search results.
    #   * Think: What does it do? Why did you write it? What is the focus?
    #   * Try to keep it short, snappy and to the point.
    #   * Write the description between the DESC delimiters below.
    #   * Finally, don't worry about the indent, CocoaPods strips it!
    
    s.description      = <<-DESC
    TODO: Add long description of the pod here.
    DESC
    
    s.homepage         = 'https://github.com/GuiLQing/LGEnglishTrainingFramework'
    # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
    s.license          = { :type => 'MIT', :file => 'LICENSE' }
    s.author           = { 'GuiLQing' => 'gui950823@126.com' }
    s.source           = { :git => 'https://github.com/GuiLQing/LGEnglishTrainingFramework.git', :tag => s.version.to_s }
    s.ios.deployment_target = '9.0'
    
    #系统依赖库
    s.frameworks = 'AudioToolbox', 'AVFoundation', 'CoreGraphics', 'CoreMedia', 'CoreVideo', 'MediaPlayer', 'MobileCoreServices', 'OpenGLES', 'QuartzCore', 'UIKit', 'VideoToolbox', 'Accelerate'
    s.libraries = 'z', 'bz2', 'stdc++'
    s.requires_arc = true
    s.static_framework  =  true
    
    #需要包含的源文件
    s.source_files = 'LGEnglishTrainingFramework/Classes/LGEnglishTrainingFramework.framework/Headers/*.{h}'
    
    #你的SDK路径
    s.vendored_frameworks = 'LGEnglishTrainingFramework/Classes/LGEnglishTrainingFramework.framework'
    
    s.resources = 'LGEnglishTrainingFramework/Classes/LGEnglishTrainingFramework.bundle'
    
    s.dependency 'AFNetworking'
    s.dependency 'Masonry'
    s.dependency 'JSONModel'
    s.dependency 'SDWebImage'
    s.dependency 'Reachability'
    s.dependency 'ReactiveObjC'
    s.dependency 'MJRefresh'
    s.dependency 'Charts','~> 3.1.1'
    s.dependency 'MarqueeLabel','~> 3.2.0'
    s.dependency 'MBProgressHUD','~> 1.1.0'
    s.dependency 'YYText'
    s.dependency 'MJExtension'
    s.dependency 'YJTaskMark'
    s.dependency 'YJMediaPlayer'
    s.dependency 'YJPresentAnimation'
    s.dependency 'SGTools'
    s.dependency 'PSGChainedMode'
    
end
