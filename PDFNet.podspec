Pod::Spec.new do |s|
  s.name                = 'PDFNet'
  s.version             = '3.0.3-18'
  s.homepage            = 'https://pdftron.com'
  s.author              = { 'PDFNet' => 'support@pdfnet.com' }
  s.license             = { :type => 'Commercial', :file => 'PDFNet.xcframework/LICENSE' }
  s.summary             = 'The complete PDF toolkit.'
  s.description         = <<-DESC
                          The complete PDF toolkit.
                          DESC
  s.platform            = :ios, '11.0'
  s.source              = { :git => 'https://github.com/testluminpdf/PDFNet.git' }

  s.preserve_paths      = 'PDFNet.xcframework', 'Tools.xcframework'
  s.vendored_frameworks = 'PDFNet.xcframework', 'Tools.xcframework'

  s.resources           = 'Tools-Localization'

  s.library             = 'z', 'c++'
  s.xcconfig            = { 'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/PDFNet/**"' }
  s.frameworks          = 'QuartzCore', 'CoreText', 'CoreMedia', 'MediaPlayer', 'AVFoundation',
                          'CoreGraphics', 'Foundation', 'MobileCoreServices', 'SystemConfiguration',
                          'UIKit','CoreImage'
  s.requires_arc        = true
end
