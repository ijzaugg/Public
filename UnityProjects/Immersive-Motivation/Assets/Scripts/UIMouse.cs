using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UIMouse : MonoBehaviour
{
    private GameObject surveyCanvas;
    private GameObject playerCam;
    private GameObject staticCam;
    private GameObject player;

    public GameObject nextWindow;

    void Start()
    {
        surveyCanvas = this.gameObject;
        playerCam = GameObject.Find("PlayerCam");
        staticCam = GameObject.Find("StaticCam");
        player = GameObject.Find("Player");
    }
    void Update()
    {
        if (surveyCanvas.activeInHierarchy)
        {
            nextWindow.SetActive(false);
            setActive();
        }
    }

    public void setActive()
    {
        playerCam.SetActive(false);
        staticCam.SetActive(true);
        player.SetActive(false);
        Cursor.lockState = CursorLockMode.Confined;
        Cursor.visible = true;
    }

    public void setInactive()
    {
        playerCam.SetActive(true);
        staticCam.SetActive(false);
        player.SetActive(true);
        Cursor.lockState = CursorLockMode.None;
        Cursor.visible = false;
        nextWindow.SetActive(true);
        surveyCanvas.SetActive(false);
    }
}