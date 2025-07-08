using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;

public class GameManager : MonoBehaviour
{
    public GameObject seed; // Reference to the seed GameObject
    public GameObject tree; // Reference to the tree GameObject
    public GameObject player; // Reference to the player GameObject

    private void Start()
    {
        Debug.Log("GameManager started");
        // Start the seed growth coroutine
        StartCoroutine(GrowSeed());
    }

    private void Update()
    {
        // Check if both player and tree are alive
        if (player != null && tree != null)
        {
            Debug.Log("Both player and tree are alive");
            // If 3 minutes have passed and both player and tree are still alive, switch to Win scene
            if (Time.timeSinceLevelLoad >= 180f)
            {
                Debug.Log("Win condition met");
                SceneManager.LoadScene("Win");
            }
        }
        else // If player or tree dies, switch to Lose scene
        {
            Debug.Log("Player or tree died");
            SceneManager.LoadScene("Lose");
        }
    }

    IEnumerator GrowSeed()
    {
        Debug.Log("Seed growth coroutine started");
        // Initial scale of the seed (small)
        Vector3 initialScale = Vector3.one * 0.1f;

        // Target scale of the seed (regular size)
        Vector3 targetScale = Vector3.one;

        // Time taken for the seed to grow (3 minutes)
        float growthTime = 180f;

        float elapsedTime = 0f;

        while (elapsedTime < growthTime)
        {
            // Interpolate scale from initial to target over time
            seed.transform.localScale = Vector3.Lerp(initialScale, targetScale, elapsedTime / growthTime);

            // Increment elapsed time
            elapsedTime += Time.deltaTime;

            yield return null;
        }

        // Ensure the seed reaches its target scale
        seed.transform.localScale = targetScale;
    }
}
