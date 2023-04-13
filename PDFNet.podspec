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
  s.source              = { :http => 'https://doc-14-3k-docs.googleusercontent.com/docs/securesc/a3mhd4hupq8evbkt6jal4f8pcaoc0p7t/hkmcnspihuckr1e3djs4228jgoip18gr/1681362150000/01920018352945907094/01920018352945907094/1kvdR2SW2PNGUUbDpcxVkqTpfCB4X_e7y?e=download&ax=ALy03A51DOpq56h8pPabMs5YkG_b49xZju92UPfWtV-x_UEq3e7RJ625SB4SUzpA1CdZwC6ThcuIzOIs4cKjpP1w4LFgGNadKqXXoXTwb-6NTEY51Kq4XpNq0RF-NO_UAx5rKM6ahRewo54yyHw_kgE2uLNpv-2UiCaq3DRRN7OJhzlgrwYr8rlEADOAhXNVOVod3YkFdzWDzYwskfC2HfWr8A7hA-vqbrL4n8LZ9-Js59q8pl7jFdSI6Yci3Mg6ReL9ijPIsq4mptPxWPwn-QXA3PvgRkF7fdAilqVUJdE4J-Yxh7SCpahRw_QplsE-ob1io_GA-tMf5jmzElJ_4xjvqtVmzxIZS6x6g0Nr0MSieESBSbTJiPRa0FwVJtneEK90df3jcJXc5grdWIQ4gOJykaxCXyV6Wwp1lqdX0o_uH-hOJ9JMJgvuwBWvrnSFjeNTN45MhKER6uC1_nYZHm7It0os-HRCPTFcktefOtfVQ9iZYmjLszv2rHELW6N4v2hulU1tBQybk9Bl0P519zsK2ai10MShfnD_-kX-UBtoMxPJ5FbWhQ-8Pv_o3IT0rrcp8JiZ1UrB2js3kEiN3JdgG7RlG32Iqs26nu6OScJQ-idqjNbhR0ukTIjp_XyaZezmjKLS7YNU6ZiQp2uQrLm2Z6PND_En3NHKK-JO-mQ-7W99AUdZ5WavBqglR7CABMSCkHcFtdbpSWR0uMrlzZgrbRaQqXQ7VsCSiDEpyOi2-b9ZWk8gQUDz2-osCZaA0pSkc9rGdUjPX6iMbzr_hhl9l7qPnu2TUZTVy1T5MvP_9bPfCx_B7b0vBjw4jbaB6S8Os3Z4-HwhjcrnSE_QOqO03WhBsMMmyoIAR9S0GJdVgXa6a9UkcgeH2pH7c1emW02DcnFIp55mfTMYrFsl8YTScbFzsw4hPvLh9bhVMfLDPC34eg1uex_KqXsFzkB9sw3lJs36KQCOTBlrdIC-D7VyEhue7fwA5FuYdqRA2ZVFmPZEpSJ2BkaX6ouXmufsEWsNEE40iULP0fFmQCHZpC_zpOAJYgPSticdk7MsLVI3z7J41992u1t-e7FGhfGesbEJsktzhnqyfqDzkcnLIQmgHDSKjgoRYP_KcmpvR_tHEmh2bipb3VcjFeQ&uuid=fb73c7c6-d405-4687-b5ac-76c31488bb54&authuser=0&nonce=qjmqeg9ds2rjq&user=01920018352945907094&hash=plrhc745e9o8sm9pqgb9j4r9jciqfpop' }

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
