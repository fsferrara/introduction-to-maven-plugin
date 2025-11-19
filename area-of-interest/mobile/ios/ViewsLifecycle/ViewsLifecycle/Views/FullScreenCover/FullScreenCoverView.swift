import SwiftUI

struct FullScreenCoverView: View {
    @Environment(\.dismiss) var dismiss

    var body: some View {
        ZStack(alignment: .topTrailing) {
            Text("This is a full screen cover view.")

            Button(action: {
                dismiss()
            }) {
                Text("Dismiss")
                    .fontWeight(.semibold)
                    .padding(.horizontal, 16)
                    .padding(.vertical, 8)
                    .background(Color.blue)
                    .foregroundColor(.white)
                    .cornerRadius(8)
            }
            .padding()
        }
        .onAppear {
            LifecycleLogger.log("FullScreenCoverView", event: "onAppear")
        }
        .onDisappear {
            LifecycleLogger.log("FullScreenCoverView", event: "onDisappear")
        }
    }
}

struct FullScreenCoverView_Previews: PreviewProvider {
    static var previews: some View {
        FullScreenCoverView()
    }
}
