Pod::Spec.new do |s|
s.name             = "SobotKit"

s.version          = "2.0.0"

s.summary          = "A marquee view used on iOS."
s.description      = <<-DESC
It is marquee view used on iOS, which implement by Objective-C.
DESC
s.homepage         = "https://github.com/ZCSDK/SobotKit"
# s.screenshots      = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
s.license          = 'MIT'
s.author           = { 'zhangxy' => 'app_dev@sobot.com' }
s.source           = { :git => "https://github.com/ZCSDK/SobotKit.git", :tag => s.version.to_s }
# s.social_media_url = 'https://twitter.com/NAME'

s.platform     = :ios, '6.1'
#s.ios.deployment_target = ‘6.1’
# s.osx.deployment_target = '10.7'
s.requires_arc = true

#s.source_files = 'SobotFramework/**/*'
# s.resources = 'Assets'

# s.ios.exclude_files = 'Classes/osx'
# s.osx.exclude_files = 'Classes/ios'
# s.public_header_files = 'Classes/**/*.h'
s.frameworks =  "AudioToolbox","AssetsLibrary","SystemConfiguration","AVFoundation","MobileCoreServices"
s.library   = 'z.1.2.5'

# s.resource  = "icon.png"
s.resources = 'SobotKit.bundle','ZCEmojiExpression.bundle','en.lproj/SobotLocalizable.strings','zh-Hans.lproj/SobotLocalizable.strings'
s.ios.vendored_frameworks = 'SobotKit.framework'
# s.ios.vendored_libraries = 'libSobotLib.a'
# s.preserve_paths = "FilesToSave", "MoreFilesToSave"


end
