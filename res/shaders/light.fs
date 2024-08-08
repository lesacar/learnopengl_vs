#version 330 core
out vec4 FragColor;

struct Light {
    vec3 position;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
  
uniform Light light;

// uniform vec3 lightCubeColor;

void main()
{
    FragColor = vec4( clamp(light.ambient + vec3(0.3), 0.0, 1.0), 1.0); // set all 4 vector values to 1.0
}
