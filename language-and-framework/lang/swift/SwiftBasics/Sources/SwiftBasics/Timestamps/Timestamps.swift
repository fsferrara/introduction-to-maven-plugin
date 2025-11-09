import Foundation

func timestamps() {
    //let systemUptimeMs = UInt64(ProcessInfo.processInfo.systemUptime * 1000)
    //print(systemUptimeMs)
    //
    //let sleepTime = TimeInterval(10) / 1000.0
    //for i in 1...9 {
    //    // currentDateMs[i] = Int64(Date().timeIntervalSince1970 * 1000)
    //    print(Int64(Date().timeIntervalSince1970 * 1000))
    //    print(Int64(Date().timeIntervalSince1970))
    //    Thread.sleep(forTimeInterval: sleepTime)
    //}


    let t: TimeInterval = TimeInterval(20) * 1000
    print(t) 

    let milliseconds: TimeInterval = Date().timeIntervalSince1970 * 1000

    let screenReadyTimeMs = UInt64(Date().timeIntervalSince1970 * 1000)

    print(screenReadyTimeMs*100000)
    print(milliseconds)
    print(Int.max)
    print(UInt64.max)
}
