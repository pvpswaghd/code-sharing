//
//  ContentView.swift
//  swiftui.learning
//
//  Created by Victor on 21/6/2022.
//

import SwiftUI

struct ContentView: View { // this is the object that displays the UI
    var body: some View {
        ZStack(content: {
            Text("Hello, what's up!").font(.body).fontWeight(.bold).foregroundColor(Color.red).padding()
            RoundedRectangle(cornerRadius: 20).stroke(lineWidth: 3).padding(.horizontal).foregroundColor(.red)
        })
        
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
