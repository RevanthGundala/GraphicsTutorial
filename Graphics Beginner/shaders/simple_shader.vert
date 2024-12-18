#version 450 core

// 3 corners of triangle (normalized b/w -1 and 1)
vec2 positions[3] = vec2[3](
	vec2(0.0, -0.5),
	vec2(0.5, 0.5),
	vec2(-0.5, 0.5)
);

void main() {
	gl_Position = vec4(positions[gl_VertexIndex], 0.0, 1.0); // 0.0 is front most layer
	gl_PointSize = 1.0;
}