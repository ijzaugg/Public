using UnityEngine;

public class FruitSpawner : MonoBehaviour
{
    public GameObject fruitPrefab; // The fruit prefab to spawn
    public Transform[] spawnPoints; // The points where fruit will be spawned
    public float spawnInterval = 5f; // Interval between fruit spawns

    void Start()
    {
        InvokeRepeating("SpawnFruit", 0f, spawnInterval);
    }

    void SpawnFruit()
    {
        Transform spawnPoint = spawnPoints[Random.Range(0, spawnPoints.Length)];
        Instantiate(fruitPrefab, spawnPoint.position, Quaternion.identity);
    }
}