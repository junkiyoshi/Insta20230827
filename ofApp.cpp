#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofSetLineWidth(1.5);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	ofColor color;
	for (int k = 0; k < 40; k++) {

		ofRotate(9);

		color.setHsb(ofMap(k, 0, 40, 0, 255), 200, 255);
		ofSetColor(color);

		vector<glm::vec2> vertices;
		for (int i = 0; i < 10; i++) {

			auto radius = k % 2 == 0 ? ofMap(sin((ofGetFrameNum() + i) * 0.314 * 0.35), -1, 1, 200, 300) : ofMap(sin((ofGetFrameNum() + i) * 0.314 * 0.35), -1, 1, 300, 200);
			auto deg = (ofGetFrameNum() + i) * 4;
			auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));

			vertices.push_back(location);
		}

		ofNoFill();
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape();

		ofFill();
		ofDrawCircle(vertices[0], 3);
		ofDrawCircle(vertices[vertices.size() - 1], 3);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}