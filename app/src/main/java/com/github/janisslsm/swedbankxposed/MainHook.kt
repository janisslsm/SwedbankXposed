package com.github.janisslsm.swedbankxposed

import de.robv.android.xposed.*
import de.robv.android.xposed.callbacks.XC_LoadPackage

class MainHook : IXposedHookLoadPackage {
    override fun handleLoadPackage(lpparam: XC_LoadPackage.LoadPackageParam) {
        if (lpparam.packageName == "lv.swedbank.mobile" ||
                lpparam.packageName == "lt.swedbank.mobile" ||
                lpparam.packageName == "com.swedbank") {
            try {
                XposedHelpers.findAndHookMethod("com.meawallet.mtp.MeaCryptoException", lpparam.classLoader, "isRootedDeviceDetected", object : XC_MethodHook() {
                    override fun afterHookedMethod(param: MethodHookParam) {
                        param.result = false;
                    }
                });
                //System.loadLibrary("swedbankxposed")
            } catch (e: Throwable) {
                XposedBridge.log(e)
            }
        }
    }
}