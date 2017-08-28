package com.example.vinh.music;

import android.bluetooth.BluetoothAdapter;
import android.media.MediaPlayer;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.ButtonBarLayout;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.TextView;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.logging.Handler;

public class MainActivity extends AppCompatActivity {
    private BluetoothAdapter BA;
    Button bt_play,bt_next,bt_prv;
    TextView txt_title;
    TextView txt_total;
    TextView txt_time;
    SeekBar sb_stt;
    ArrayList<Songs> listSongs;
    MediaPlayer mediaPlay;
    int pos = 0;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        componentCreate();
        addSong();
        initSong();
        bt_play.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View view){
               //


                if(mediaPlay.isPlaying()){
                    mediaPlay.pause();
                    bt_play.setBackgroundResource(android.R.drawable.ic_media_play);
                }
                else{
                    mediaPlay.start();
                    bt_play.setBackgroundResource(android.R.drawable.ic_media_pause);
                }
                setSongTime();

            }
        });
        bt_next.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view){
                if(mediaPlay.isPlaying())
                    mediaPlay.stop();
                //pos++;
                if(++pos > listSongs.size()-1)
                    pos = 0;
                initSong();
                mediaPlay.start();

            }
        });
        bt_prv.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view){
                if(mediaPlay.isPlaying())
                    mediaPlay.stop();
                //pos++;
                if(--pos < 0)      //restart the playist
                    pos = listSongs.size()-1;
                initSong();
                mediaPlay.start();
            }
        });
        sb_stt.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {

            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                mediaPlay.seekTo(sb_stt.getProgress());     //jump to the playing position
            }
        });

    }

    private void updatePlaying(){
        android.os.Handler handle = new android.os.Handler();
        handle.postDelayed(new Runnable() {
            @Override
            public void run() {

            }
        },100);
    }
    private void initSong(){
        mediaPlay = MediaPlayer.create(MainActivity.this,listSongs.get(pos).getFile());
        setSongTime();
    }
    private void setSongTime() {
        SimpleDateFormat timeFormat = new SimpleDateFormat("mm:ss");
        txt_total.setText(timeFormat.format(mediaPlay.getDuration()));
        sb_stt.setMax(mediaPlay.getDuration());
    }
    private void addSong() {
        listSongs = new ArrayList<>();
        listSongs.add(new Songs("Look what you make me do",R.raw.lookwhatyoumake));
        listSongs.add(new Songs("Ngoi hat do buon",R.raw.ngoihatdobuon));

    }

    private void componentCreate() {
        bt_play = (Button) findViewById(R.id.bt_play);
        bt_prv = (Button) findViewById(R.id.bt_previous);
        bt_next = (Button) findViewById(R.id.bt_next);
        txt_time = (TextView) findViewById(R.id.tv_time);
        txt_total = (TextView) findViewById(R.id.tv_total);
        sb_stt = (SeekBar) findViewById(R.id.sb_status);

    }

}
