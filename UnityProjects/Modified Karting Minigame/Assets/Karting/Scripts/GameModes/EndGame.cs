using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;

public class EndGame : MonoBehaviour
{
    // The name of the scene to load after waiting
    public string finishSceneName;

    void OnTriggerEnter(Collider other)
    {
        // Check if the trigger was entered by the player
        if (other.CompareTag("Player"))
        {
            // Start the coroutine to wait for three seconds
            StartCoroutine(WaitAndLoadScene());
        }
    }

    IEnumerator WaitAndLoadScene()
    {
        // Wait for three seconds
        yield return new WaitForSeconds(3f);

        // Load the finish scene
        SceneManager.LoadScene(finishSceneName);
    }
}
