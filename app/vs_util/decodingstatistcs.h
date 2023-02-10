#ifndef DECODINGSTATISTCS_H
#define DECODINGSTATISTCS_H

#include <QObject>

// Really nice, this way we don't have to write all the setters / getters / signals ourselves !
#include "../lib/lqtutils_master/lqtutils_prop.h"

/**
 * @brief Simple QT model (signals) to expose QOpenHD decoding statistics to the UI.
 * singleton, corresponding qt name is "_decodingStatistics" (see main)
 * Data generated by QOpenHD itself (e.g. the encoder stats from the air pi) should be handled by a different model
 * Depending on the actually used implementation, some stats might not be available
 * (e.g. when using gstreamer)
 */
class DecodingStatistcs : public QObject
{
    Q_OBJECT
    L_RO_PROP(QString, parse_and_enqueue_time, set_parse_and_enqueue_time, "?")
    L_RO_PROP(QString, decode_time, set_decode_time, "?")
    // If we do sw decode & opengl display, we drop already decoded frame(s) if a new
    // (already decoded) frame arrives before we have displayed the previous one
    L_RO_PROP(QString, decode_and_render_time, set_decode_and_render_time, "?")
    L_RO_PROP(int, n_renderer_dropped_frames, set_n_renderer_dropped_frames, -1)
    L_RO_PROP(int, n_rendered_frames, set_n_rendered_frames, -1)
    L_RO_PROP(int, udp_rx_bitrate, set_udp_rx_bitrate, -1)
    L_RO_PROP(QString, doing_wait_for_frame_decode, set_doing_wait_for_frame_decode, "?")
    L_RO_PROP(QString, primary_stream_frame_format, set_primary_stream_frame_format, "?")
    // SW or HW decode
    L_RO_PROP(QString, decoding_type, set_decoding_type, "?")
    L_RO_PROP(int, n_missing_rtp_video_packets, set_n_missing_rtp_video_packets, -1)
    // In QOpenHD (rtp udp receiver) measured bitrate
    L_RO_PROP(QString, rtp_measured_bitrate, set_rtp_measured_bitrate, "-1")
    L_RO_PROP(QString, estimate_rtp_fps, set_estimate_rtp_fps, "-1")
    L_RO_PROP(int, estimate_keyframe_interval, set_estimate_keyframe_interval, -1)
    // Not link related - n frame(s) we had to drop since the decoder cannot keep up with
    // the data stream that is provided to it
    L_RO_PROP(int,n_decoder_dropped_frames,set_n_decoder_dropped_frames,-1)
public:
    explicit DecodingStatistcs(QObject *parent = nullptr);
    static DecodingStatistcs& instance();
};

#endif // DECODINGSTATISTCS_H
