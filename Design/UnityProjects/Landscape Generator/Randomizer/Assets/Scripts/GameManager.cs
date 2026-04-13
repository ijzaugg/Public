using System.Diagnostics;
using UnityEngine;

[RequireComponent(typeof(TerrainGenerator))]
public class GameManager : MonoBehaviour
{
    public GameObject player;
    public GameObject flag;
    public float terrainWidth = 500f;
    public float terrainLength = 500f;

    private TerrainGenerator terrainGen;

    void Awake()
    {
        terrainGen = GetComponent<TerrainGenerator>();
    }

    void Start()
    {
        terrainGen.Generate();
        PositionAtRandom(player);
        PositionAtRandom(flag);
    }

    public void ResetGame()
    {
        terrainGen.Generate();
        PositionAtRandom(player);
        PositionAtRandom(flag);
    }

    void PositionAtRandom(GameObject obj)
    {
        Terrain terrain = Terrain.activeTerrain;
/*        if (terrain == null)
        {
            Debug.LogWarning("No active terrain found!");
            return;
        }*/

        Vector3 terrainPos = terrain.transform.position;
        Vector3 terrainSize = terrain.terrainData.size;

        // Generate a point within the terrain bounds
        float x = UnityEngine.Random.Range(0f, terrainSize.x);
        float z = UnityEngine.Random.Range(0f, terrainSize.z);

        // Calculate world position
        float worldX = terrainPos.x + x;
        float worldZ = terrainPos.z + z;

        // Sample terrain height at that position
        float terrainHeight = terrain.SampleHeight(new Vector3(worldX, 0, worldZ));

        // Raise object slightly above terrain (use Collider bounds if needed)
        float bufferAboveGround = 1.5f;
        float safeY = terrainHeight + terrainPos.y + bufferAboveGround;

        obj.transform.position = new Vector3(worldX, safeY, worldZ);
    }

}
