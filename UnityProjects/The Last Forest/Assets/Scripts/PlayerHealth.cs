using UnityEngine;
using UnityEngine.UI;

public class PlayerHealth : MonoBehaviour
{
    [Header("Health Settings")]
    public int maxHealth = 100; // Maximum health of the player
    public int currentHealth; // Current health of the player

    public Slider healthSlider; // Reference to the UI slider for displaying health
    public Text healthText; // Reference to the UI text for displaying health

    void Start()
    {
        currentHealth = maxHealth; // Set current health to maximum on start

        // Update UI elements
        UpdateUI();
    }

    // Method to handle damage to the player
    public void TakeDamage(int damageAmount)
    {
        currentHealth -= damageAmount; // Decrease health by the damage amount

        // Update UI elements
        UpdateUI();

        if (currentHealth <= 0)
        {
            Die(); // If health reaches zero or less, call Die method
        }
    }

    // Method to handle player death
    void Die()
    {
        // Perform any necessary actions upon player death
        Debug.Log("Player has died!");
        // For example, you could load a game over scene or reset the level
    }

    // Method to update UI elements
    void UpdateUI()
    {
        // Update health slider value
        if (healthSlider != null)
        {
            healthSlider.value = (float)currentHealth / maxHealth;
        }

        // Update health text
        if (healthText != null)
        {
            healthText.text = "Health: " + currentHealth + " / " + maxHealth;
        }
    }
}
