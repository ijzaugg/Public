using UnityEngine;
using UnityEngine.SceneManagement;

public class TreeHealth : MonoBehaviour
{
    [Header("Health Settings")]
    public int maxHitPoints = 100; // Maximum hit points of the tree
    public int currentHitPoints; // Current hit points of the tree
    public string loseSceneName = "Lose"; // Name of the scene to load when the tree is destroyed

    void Start()
    {
        currentHitPoints = maxHitPoints; // Set current hit points to maximum on start
    }

    // Method to handle damage to the tree
    public void TakeDamage(int damageAmount)
    {
        currentHitPoints -= damageAmount; // Decrease hit points by the damage amount

        if (currentHitPoints <= 0)
        {
            Die(); // If hit points reach zero or less, call Die method
        }
    }

    // Method to handle tree destruction
    void Die()
    {
        // Load the lose scene
        SceneManager.LoadScene(loseSceneName);
    }
}
