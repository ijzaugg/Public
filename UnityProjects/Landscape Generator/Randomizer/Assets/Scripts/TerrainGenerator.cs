using UnityEngine;

public class TerrainGenerator : MonoBehaviour
{
    public Terrain terrain;
    public int width = 512;
    public int height = 512;
    public float scale = 20f;

    void Start()
    {
        Generate();
    }

    public void Generate()
    {
        float[,] heights = new float[width, height];

        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                float xCoord = (float)x / width * scale;
                float yCoord = (float)y / height * scale;

                float heightValue = Mathf.PerlinNoise(xCoord, yCoord);

                heights[x, y] = heightValue * 0.2f; // Lower this value to flatten terrain (e.g., 0.1 = very flat)
            }
        }

        terrain.terrainData.heightmapResolution = width + 1;
        terrain.terrainData.size = new Vector3(width, 50, height); // Vertical scale still affects steepness
        terrain.terrainData.SetHeights(0, 0, heights);
    }
}
