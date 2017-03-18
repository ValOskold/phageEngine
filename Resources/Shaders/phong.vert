#version 400

//Vertex in
in vec3 vPosition;
in vec3 vNormal;
in vec2 vTexCoord;
in vec3 vTangent;
in vec3 vBiTangent;

//View matrix in
uniform mat4 cameraView;
uniform mat4 modelView;
uniform mat4 projView;

//Camera position out
out mat4 fCameraView;
out mat4 fModelView;

//Vertex position and normal out
out vec3 fPosition;
out vec3 fNormal;
out vec2 fTexCoord;
out vec3 fColor;
out vec3 fTangent;
out vec3 fBiTangent;

void main(){
	mat4 modelViewMatrix = cameraView * modelView;

	vec4 viewModelPosition = modelViewMatrix * vec4(vPosition, 1);

	fPosition = (modelView * vec4(vPosition, 1)).xyz;
	fTexCoord = vTexCoord;

	fModelView = modelView;
	fCameraView = cameraView;

	mat3 normalMatrix = transpose(inverse(mat3(modelView)));

	fNormal = normalize(normalMatrix * vNormal);

	gl_Position = projView * viewModelPosition;
}