package com.github.janisslsm.swedbankxposed

import de.robv.android.xposed.*
import de.robv.android.xposed.callbacks.XC_LoadPackage

class MainHook : IXposedHookLoadPackage {
    override fun handleLoadPackage(lpparam: XC_LoadPackage.LoadPackageParam) {
        if (lpparam.packageName == "lv.swedbank.mobile") {
            try {
                System.loadLibrary("swedbankxposed")
            } catch (e: Throwable) {
                XposedBridge.log(e)
            }
        }
    }
}