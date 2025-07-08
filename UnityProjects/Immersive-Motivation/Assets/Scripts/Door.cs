using System.Collections;
using System.Collections.Generic;
using System;
using UnityEngine;


public class Door : MonoBehaviour
{
    public Cauldron cauldron;
    public CharacterController playerController;
    private bool isUnlocked = false;
    private bool isOpen = false;
    public Animator anim;
    public static float minDistance = 10.5f;
    void Start(){
        anim.SetBool("isOpened", false);
    }

    // Update is called once per frame
    void Update()
    {
        //*
        /*print("isOpen = " + isOpen);
        print("isUnlocked = " + isUnlocked);
        print("Player Distance: " + getPlayerDistance());
        print("Within proximity: " + (getPlayerDistance() <= minDistance));*/
        
        if(isOpen) {
            anim.SetBool("isOpened", true);
        }
        else if(isUnlocked && getPlayerDistance() <= minDistance) {
            isOpen = true;
            anim.SetBool("isOpened", true);
        }
        //*/
        // else do nothing
    }

    /*
    void onClick() {
        print("isUnlocked = " + isUnlocked);

        if(isUnlocked) {
            isOpen = true;
            anim.SetBool("isOpened", true);
        }
        // else do nothing
    }//*/

    private float getPlayerDistance() {
        Vector3 offset = transform.position - playerController.transform.position;
        return (float)(Math.Sqrt(Math.Pow(offset.x, 2) + Math.Pow(offset.y, 2) + Math.Pow(offset.z, 2)));
    }
    
    public void unlock() {
        isUnlocked = true;
    }

    public bool open() {
        return isOpen;
    }
}
