#pragma once

#include <gio/gio.h>
#include <glib-object.h>
#include <gst/gst.h>
#include <pulse/pulseaudio.h>

G_BEGIN_DECLS

#define ND_TYPE_PULSEAUDIO (nd_pulseaudio_get_type ())
typedef void (*nd_pa_sink_changed_cb_t) (gboolean use_dnd_sink,void *user_data);

G_DECLARE_FINAL_TYPE (NdPulseaudio, nd_pulseaudio, ND, PULSEAUDIO, GObject)

NdPulseaudio *nd_pulseaudio_new (void);

GstElement           *nd_pulseaudio_get_source (NdPulseaudio *self);
void nd_pulseaudio_set_sink (NdPulseaudio *self);
void nd_pulseaudio_set_sink_changed_cb (NdPulseaudio *self, nd_pa_sink_changed_cb_t cb, void *userdata);

void nd_pulseaudio_sync_state (NdPulseaudio *self);
void nd_pulseaudio_unload_module (NdPulseaudio *self, pa_context_success_cb_t cb, void *userdata);
G_END_DECLS
