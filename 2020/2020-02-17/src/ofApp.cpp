#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  std::string file = "sample.json";
  bool parsingSuccessful = result.open(file);
    
    if (parsingSuccessful)
      {
          ofLogNotice("ofApp::setup") << result.getRawString();

          // now write pretty print
          if (!result.save("example_output_pretty.json", true))
          {
              ofLogNotice("ofApp::setup") << "example_output_pretty.json written unsuccessfully.";
          }
          else
          {
              ofLogNotice("ofApp::setup") << "example_output_pretty.json written successfully.";
          }

          // now write without pretty print
          if (!result.save("example_output_fast.json", false))
          {
              ofLogNotice("ofApp::setup") << "example_output_pretty.json written unsuccessfully.";
          }
          else
          {
              ofLogNotice("ofApp::setup") << "example_output_pretty.json written successfully.";
          }

      }
      else
      {
          ofLogError("ofApp::setup")  << "Failed to parse JSON" << endl;
      }

    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  std::stringstream ss;
  ss << "firstName          = " << result["firstName"].asString() << std::endl;
  ss << "lastName           = " << result["lastName"].asString() << std::endl;
  ofDrawBitmapString(ss.str(), 10, 14);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
