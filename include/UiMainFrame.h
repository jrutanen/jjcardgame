#ifndef UIMAINFRAME_H
#define UIMAINFRAME_H


class UiMainFrame: public wxFrame
{
  public:
    UiMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    virtual ~UiMainFrame();
  protected:
  private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};

#endif // UIMAINFRAME_H
