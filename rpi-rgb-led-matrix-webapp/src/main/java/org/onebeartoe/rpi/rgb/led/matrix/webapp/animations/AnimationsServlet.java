
package org.onebeartoe.rpi.rgb.led.matrix.webapp.animations;

import java.io.File;
import java.io.FilenameFilter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.onebeartoe.rpi.rgb.led.matrix.webapp.RaspberryPiRgbLedMatrixServlet;

/**
 *
 * @author Roberto Marquez <https://www.youtube.com/user/onebeartoe>
 * 
 */
@WebServlet(name = "AnimationsServet", urlPatterns = {"/animations/*"})
public class AnimationsServlet extends RaspberryPiRgbLedMatrixServlet
{
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    {
        doResponse(request, response);
    }
    
    protected void doResponse(HttpServletRequest request, HttpServletResponse response)
    {
        File animationsDir = new File( ledMatrix.getAnimationsPath() );
        String [] fileNames = animationsDir.list(new FilenameFilter() 
        {
            @Override
            public boolean accept(File dir, String name) 
            {
                return name.endsWith(".gif");
            }
        });
        request.setAttribute("animationNames", fileNames);

        ServletContext c = getServletContext();
        RequestDispatcher rd = c.getRequestDispatcher("/WEB-INF/jsp/animations/index.jsp");
        try
        {
            rd.forward(request, response);
        } 
        catch (IOException | ServletException ex)
        {
            Logger.getLogger(AnimationsServlet.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
