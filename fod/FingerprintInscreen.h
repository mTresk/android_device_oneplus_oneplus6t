/*
 * Copyright (C) 2019 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef VENDOR_OMNI_BIOMETRICS_FINGERPRINT_INSCREEN_V1_1_FINGERPRINTINSCREEN_H
#define VENDOR_OMNI_BIOMETRICS_FINGERPRINT_INSCREEN_V1_1_FINGERPRINTINSCREEN_H

#include <vendor/omni/biometrics/fingerprint/inscreen/1.1/IFingerprintInscreen.h>
#include <vendor/oneplus/fingerprint/extension/1.0/IVendorFingerprintExtensions.h>
#include <vendor/oneplus/hardware/display/1.0/IOneplusDisplay.h>

namespace vendor {
namespace omni {
namespace biometrics {
namespace fingerprint {
namespace inscreen {
namespace V1_1 {
namespace implementation {

using ::android::sp;
using ::android::hardware::Return;
using ::android::hardware::Void;
using V1_0::IFingerprintInscreenCallback;
using ::vendor::oneplus::fingerprint::extension::V1_0::IVendorFingerprintExtensions;
using ::vendor::oneplus::hardware::display::V1_0::IOneplusDisplay;

class FingerprintInscreen : public IFingerprintInscreen {
  public:
    FingerprintInscreen();

    Return<void> onStartEnroll() override;
    Return<void> onFinishEnroll() override;
    Return<void> onPress() override;
    Return<void> onRelease() override;
    Return<void> onShowFODView() override;
    Return<void> onHideFODView() override;
    Return<bool> handleAcquired(int32_t acquiredInfo, int32_t vendorCode) override;
    Return<bool> handleError(int32_t error, int32_t vendorCode) override;
    Return<void> setLongPressEnabled(bool enabled) override;
    Return<int32_t> getDimAmount(int32_t cur_brightness) override;
    Return<bool> shouldBoostBrightness() override;
    Return<void> setCallback(const sp<IFingerprintInscreenCallback>& callback) override;
    Return<int32_t> getPositionX() override;
    Return<int32_t> getPositionY() override;
    Return<int32_t> getSize() override;


    Return<void> switchHbm(bool enabled) override;
    Return<bool> supportsAlwaysOnHBM() override;
    Return<int32_t> getHbmOffDelay() override;
    Return<int32_t> getHbmOnDelay() override;

  private:
    bool mFodCircleVisible;
    sp<IOneplusDisplay> mVendorDisplayService;
    sp<IVendorFingerprintExtensions> mVendorFpService;

    std::mutex mCallbackLock;
    sp<IFingerprintInscreenCallback> mCallback;
};

}  // namespace implementation
}  // namespace V1_1
}  // namespace inscreen
}  // namespace fingerprint
}  // namespace biometrics
}  // namespace omni
}  // namespace vendor

#endif  // VENDOR_OMNI_BIOMETRICS_FINGERPRINT_INSCREEN_V1_1_FINGERPRINTINSCREEN_H
