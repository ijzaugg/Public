using UnityEngine;
using UnityEngine.SceneManagement;

public class FlagTrigger : MonoBehaviour
{
    private GameManager gameManager;

    void Start()
    {
        gameManager = FindObjectOfType<GameManager>();
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Flag"))
        {
            gameManager.ResetGame();
        }
    }
}

