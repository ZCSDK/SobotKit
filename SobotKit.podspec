Pod::Spec.new do |s|
s.name             = "SobotKit"

s.version          = "3.0.8"

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

s.platform     = :ios, '8.0'
#s.ios.deployment_target = ‘6.1’
# s.osx.deployment_target = '10.7'
s.requires_arc = true

s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }

#s.source_files = 'SobotFramework/**/*'
# s.resources = 'Assets'

# s.ios.exclude_files = 'Classes/osx'
# s.osx.exclude_files = 'Classes/ios'
# s.public_header_files = 'Classes/**/*.h'
s.frameworks =  "AudioToolbox","AssetsLibrary","SystemConfiguration","AVFoundation","MobileCoreServices","WebKit"
#s.library   = 'z.1.2.5'

# s.resource  = "icon.png"
s.resources = 'SobotKit.bundle'
s.ios.vendored_frameworks = 'SobotKit.framework'

# s.ios.vendored_libraries = 'libSobotLib.a'
# s.preserve_paths = "FilesToSave", "MoreFilesToSave"


end
