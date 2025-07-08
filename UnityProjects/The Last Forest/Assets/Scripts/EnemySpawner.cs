using UnityEngine;

public class EnemySpawner : MonoBehaviour
{
    public GameObject enemyPrefab; // Reference to the enemy prefab
    public Vector3 treePosition; // Position where the tree is located
    public float spawnRadius = 10f; // Radius around the tree position where enemies can spawn
    public float spawnInterval = 3f; // Interval between enemy spawns
    public int maxEnemies = 10; // Maximum number of enemies to spawn

    private int currentEnemies = 0; // Current number of spawned enemies

    void Start()
    {
        // Start spawning enemies at regular intervals
        InvokeRepeating("SpawnEnemy", 0f, spawnInterval);
    }

    void Awake()
    {
        // Ensure that the GameObject this script is attached to persists between scenes
        DontDestroyOnLoad(gameObject);
    }

    void SpawnEnemy()
    {
        if (currentEnemies < maxEnemies)
        {
            // Calculate a random position within the spawn radius
            Vector3 randomOffset = Random.insideUnitSphere * spawnRadius;
            randomOffset.y = 0f; // Ensure enemies spawn at ground level

            // Offset the position relative to the tree's position
            Vector3 spawnPosition = treePosition + randomOffset;

            // Instantiate the enemy at the calculated position
            GameObject newEnemy = Instantiate(enemyPrefab, spawnPosition, Quaternion.identity);
            currentEnemies++;
        }
    }
}
