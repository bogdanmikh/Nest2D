#version 330

in vec2 TexCoord;

uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;

uniform sampler2D texture1;

out vec4 fragColor;

void main(){
    vec2 st = gl_FragCoord.xy / u_resolution;
    vec2 m = gl_FragCoord.xy / u_mouse;
    //m.x, m.y, abs(sin(u_time))
	fragColor = vec4(1.0, 1.0, 1.0, 1.0) * texture(texture1, TexCoord);
}